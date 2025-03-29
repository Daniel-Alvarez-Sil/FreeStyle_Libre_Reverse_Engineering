# pypn5180_15693.py

if __name__ == "__main__":

    args = parseInputs()

    isoIec15693 = iso_iec_15693(args.ftdi_port) # Creation of an isoIEC15693 Instance
    sys_info, errStr = isoIec15693.getSystemInformationCmd()
    serial = binascii.hexlify(bytes(sys_info[1:9])).decode('utf-8')
    print('[%s] SysInfo - chip serial: %r' %(errStr, serial))

    elif args.mode == "CUSTOM":
        if args.data is not "":
            dataIn = list(binascii.unhexlify(args.data))
        else:
            dataIn = []
        cmdCode = ord(binascii.unhexlify(args.custom))
        mfCode = ord(binascii.unhexlify(args.mfCode))
        print("Sending Code 0x%x with %r" %(cmdCode,dataIn))
        data, errStr  = isoIec15693.customCommand(cmdCode, mfCode, dataIn)
        if "No Answer from tag" not in errStr: 
            print("CMD %x: [%s] Data: [%r] - [%s]" %(cmdCode, errStr, data, binascii.hexlify(data)))
        else:
            print("%s" %errStr)

# iso_iec_15693.py
def customCommand(self, cmdCode, mfCode, data):
        # 'A0' - 'DF' Custom IC Mfg dependent
        # 'E0' - 'FF' Proprietary IC Mfg dependent
        frame = []
        frame.insert(0, self.flags)
        frame.insert(1, cmdCode)
        frame.insert(2, mfCode)
        if data is not []:
            frame.extend(data)
        flags, data = self.pn5180.transactionIsoIec15693(frame)
        error = self.getError(flags, data)
        return data, error

    """
    Note: firstBlockNumber: 2 bytes, LSB first
    """

# pypn5180.py
"""
transactionIsoIec15693(cmd)
Perform RF transaction. Send command to the RFiD device and read device result.
"""
def transactionIsoIec15693(self, command):
    self.setSystemCommand("COMMAND_TRANSCEIVE_SET")

    # Check RF_STATUS TRANSCEIVE_STATE value
    # must be WAIT_TRANSMIT
    if self.getRfStatusTransceiveState() is not "WAIT_TRANSMIT":
        print("transactionIsoIec15693 Error in RF state: %s" %self.getRfStatusTransceiveState())
        return -1 
    
    self.sendData(8,command)
    self._usDelay(50000) # 50 ms
    nbBytes = self.getRxStatusNbBytesReceived()
    response = self.readData(nbBytes)
    if response:
        flags = response[0]
        data = response[1:]
        # print("Received %d bytes from sensor: [flags]: %x, [data]: %r" %(nbBytes, flags, [hex(x) for x in data]))
    else:
        flags = 0xFF
        data = []

    self.setSystemCommand("COMMAND_IDLE_SET")

    return flags, data
