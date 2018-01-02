//
//  BlowFishStringEncryption.h
//  BlowFish String Encryption
//
//  Created by Joseph Lyons on 1/1/18.
//

#ifndef BlowFishStringEncryption_h
#define BlowFishStringEncryption_h

#include "../JuceLibraryCode/JuceHeader.h"

String encryptStringWithBlowFish (const String &key, const String &textToEncrypt);
String decryptStringWithBlowFish (const String &key, const String &textToDecrypt);

#endif /* BlowFishStringEncryption_h */
