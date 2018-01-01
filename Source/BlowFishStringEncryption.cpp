//
//  BlowFishStringEncryption.cpp
//  BlowFish String Encryption - ConsoleApp
//
//  Created by Joseph Lyons on 1/1/18.
//

#include "BlowFishStringEncryption.h"

String encryptStringWithBlowFish (const String &key, const String &textToEncrypt)
{
    MemoryBlock mb;
    MemoryOutputStream os (mb, false);
    os << textToEncrypt;
    
    BlowFish blowFish (key.toUTF8(), (int) key.getNumBytesAsUTF8());
    blowFish.encrypt (mb);
    
    return mb.toBase64Encoding();
}

String decryptStringWithBlowFish (const String &key, String &textToDecrypt)
{
    MemoryBlock mb;
    mb.fromBase64Encoding(textToDecrypt);
    
    BlowFish blowFish (key.toUTF8(), (int) key.getNumBytesAsUTF8());
    blowFish.decrypt (mb);
    
    return mb.toString();
}
