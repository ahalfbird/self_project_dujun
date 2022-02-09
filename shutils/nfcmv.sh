#!/bin/bash

echo "this is a bash sh to generate copy file"

NFC_SOURCE_CODE=$1

rm -rf system/nfc packages/apps/Nfc vendor/nxp/opensource hardware/nxp packages/apps/SecureElement frameworks/base/core/java/android/nfc frameworks/base/core/java/android/se


    cp -r ${NFC_SOURCE_CODE}/system/nfc system/
     echo "copy system/nfc"
 
 
    cp -r ${NFC_SOURCE_CODE}/hardware/nxp hardware/
     echo "copy hardware/nxp"
 
 
    cp -r ${NFC_SOURCE_CODE}/frameworks/base/core/java/android/nfc frameworks/base/core/java/android/
     echo "copy frameworks/base/core/java/android/nfc"
 
 
    cp -r ${NFC_SOURCE_CODE}/frameworks/base/core/java/android/se frameworks/base/core/java/android/
     echo "copy frameworks/base/core/java/android/se"
 
 
    cp -r ${NFC_SOURCE_CODE}/vendor/nxp vendor/
     echo "copy vendor/nxp"
 
 
    cp -r ${NFC_SOURCE_CODE}/packages/apps/Nfc packages/apps/
     echo "copy packages/apps/Nfc"
 
 
    cp -r ${NFC_SOURCE_CODE}/packages/apps/SecureElement packages/apps/
     echo "copy packages/apps/SecureElement"