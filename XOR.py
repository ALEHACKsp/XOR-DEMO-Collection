def XOR(data, key):
    FinalData = bytearray()
    Data = [data[i:i+1] for i in range(len(data))]
    Key = [key[i:i+1] for i in range(len(key))]
    j = 0
    for i in range(len(Data)):
        FinalData.extend(bytes([int.from_bytes(Data[i],"big") ^ int.from_bytes(Key[j],"big")]))
        j += 1
        if(j >= len(Key)):
            j = 0
    return bytes(FinalData)
    

RawData = "Hello World".encode('ascii')
Key = "123".encode('ascii')

print(RawData)
print(Key)

Data = XOR(RawData, Key)

print(Data)
print(XOR(Data, Key))

