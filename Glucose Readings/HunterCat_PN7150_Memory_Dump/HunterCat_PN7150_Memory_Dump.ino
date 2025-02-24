#include "Electroniccats_PN7150.h"

// Define IRQ and VEN pins based on architecture
#ifdef ARDUINO_ARCH_SAMD
#define PN7150_IRQ   (15)
#define PN7150_VEN   (14)
#else
#define PN7150_IRQ   (18)
#define PN7150_VEN   (17)
#endif

#define PN7150_ADDR (0x28)
#define TOTAL_BLOCKS_ISO15693 (244)  // Total number of blocks to read

Electroniccats_PN7150 nfc(PN7150_IRQ, PN7150_VEN, PN7150_ADDR);  

void PrintBuf(const byte* data, const uint32_t numBytes) {  
  for (uint32_t i = 0; i < numBytes; i++) {
    Serial.print(F("0x"));
    if (data[i] <= 0xF)
      Serial.print(F("0"));
    Serial.print(data[i] & 0xff, HEX);
    if (i != numBytes - 1)
      Serial.print(F(" "));
  }
  Serial.println();
}

void ReadAllISO15693Blocks() {
  bool status;
  unsigned char Resp[256];
  unsigned char RespSize;
  
  Serial.println("\nReading all blocks...");

  for (int block = 0; block < TOTAL_BLOCKS_ISO15693; block++) {
    unsigned char ReadBlockCmd[] = {0x02, 0x20, (unsigned char)block};
    
    status = nfc.readerTagCmd(ReadBlockCmd, sizeof(ReadBlockCmd), Resp, &RespSize);
    
    if ((status == NFC_ERROR) || (Resp[RespSize - 1] != 0x00)) {
      Serial.print("Error reading block: ");
      Serial.print(block, HEX);
      Serial.print(" with error: ");
      Serial.println(Resp[RespSize - 1], HEX);
      continue;  // Skip this block and continue reading others
    }

    Serial.print("Block ");
    Serial.print(block);
    Serial.print(": ");
    PrintBuf(Resp + 1, RespSize - 2);  // Print block data
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Reading all ISO15693 data blocks with PN7150");

  Serial.println("Initializing NFC...");
  if (nfc.connectNCI()) {  
    Serial.println("Error while setting up the mode, check connections!");
    while (1);
  }

  if (nfc.configureSettings()) {
    Serial.println("Configuration failed!");
    while (1);
  }

  if (nfc.configMode()) {  
    Serial.println("Mode setup failed!");
    while (1);
  }

  nfc.startDiscovery();
  Serial.println("Waiting for an ISO15693 Card...");
}

void loop() {
  if (nfc.isTagDetected()) {
    switch (nfc.remoteDevice.getProtocol()) {
      case nfc.protocol.ISO15693:
        Serial.println(" - Found ISO15693 card");

        Serial.print("\tID = ");
        PrintBuf(nfc.remoteDevice.getID(), sizeof(nfc.remoteDevice.getID()));

        Serial.print("\tAFI = ");
        Serial.println(nfc.remoteDevice.getAFI(), HEX);

        Serial.print("\tDSFID = ");
        Serial.println(nfc.remoteDevice.getDSFID(), HEX);

        ReadAllISO15693Blocks();  // Read all blocks from the card
        break;

      default:
        Serial.println(" - Found a card, but it is not ISO15693!");
        break;
    }

    if (nfc.remoteDevice.hasMoreTags()) {
      nfc.activateNextTagDiscovery();
    }
    
    Serial.println("Remove the Card");
    nfc.waitForTagRemoval();
    Serial.println("CARD REMOVED!");
  }

  nfc.reset();
  Serial.println("Waiting for an ISO15693 Card...");
  delay(500);
}
