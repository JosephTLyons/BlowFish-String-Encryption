//
//  BlowFishStringEncryption.cpp
//  BlowFish String Encryption - ConsoleApp
//
//  Created by Joseph Lyons on 1/1/18.
//

#include "BlowFishStringEncryption.h"

String encryptStringWithBlowFish (const String &key, const String &textToEncrypt)
{
    MemoryBlock memoryBlock;
    
    MemoryOutputStream memoryOutputStream (memoryBlock, false);
    memoryOutputStream << textToEncrypt;
    
    BlowFish blowFish (key.toUTF8(), (int) key.getNumBytesAsUTF8());
    blowFish.encrypt (memoryBlock);
    
    return memoryBlock.toBase64Encoding();
}

String decryptStringWithBlowFish (const String &key, const String &textToDecrypt)
{
    MemoryBlock memoryBlock;
    memoryBlock.fromBase64Encoding (textToDecrypt);
    
    BlowFish blowFish (key.toUTF8(), (int) key.getNumBytesAsUTF8());
    blowFish.decrypt (memoryBlock);
    
    return memoryBlock.toString();
}
