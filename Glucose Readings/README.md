# Glucose Readings (without credentials) of a FreeStyle Libre
## Instructions for Implementation

1. Download the .ino filefrom the [**HunterCat_PN7150_Memory_Dump**](https://github.com/Daniel-Alvarez-Sil/FreeStyle_Libre_Reverse_Engineering/tree/main/Glucose%20Readings/HunterCat_PN7150_Memory_Dump) directory and upload into your Hunter Cat NFC. For more information on how to upload your Arduino code to the device, check [**this**](https://github.com/ElectronicCats/HunterCatNFC/wiki/3.--Understanding-Hunter-Cat-NFC#enter-bootloader-mode).

     > NOTE:
      > For the Hunter Cat NFC v.2 or newer, even though the documentation does not state it, you can upload the Arduino Code by selection Raspberry Pico as your board. By doing so, you need not to enter bootloader mode. 
3. Close the Arduino IDE to make the serial port available.
4. Download and open the [**Jupyter Notebook**](https://github.com/Daniel-Alvarez-Sil/FreeStyle_Libre_Reverse_Engineering/blob/main/Glucose%20Readings/glucometer_real_time.ipynb).
5. Modify the serial port if necessary (by default set to COM 7)
6. Run the whole Jupyter Notebook.
7. Place your sensor near the Hunter Cat NFC device.
   
## Explanation
The Arduino routine makes a memory dump of the FreeStyle Libre by reading all the blocks available, 244 in this case. According to the repositories mentioned 
in the main README, the information for trends and historic glucose data is stored starting in the fourth byte of the third block of memory (both zero-indexed). 
Records from both, trends and historic data, occupy 6 bytes of information. It is important to note that there are 16 slots for trends and 32 for historic data. 

Next, the Python routine takes the memory blocks as input and obtains the 16 values of trend data, as well as the 32 values of historic data. Finally, the decimal value for glucose is obtained
and displayed both in a graphic and in tabular form. 
