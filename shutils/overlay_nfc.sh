#!/bin/bash
###This file is rename android.bp/android.mk and move to project dir.

NFC_SOURCE_CODE=$(pwd)/device/qcom/mc582/qcom_nfc_code
###recovery android.* to Android.*
find $NFC_SOURCE_CODE -type f -name android.bp -exec sh -c ' for f; 
do
mv "$f" "${f/%android.bp/Android.bp}";
done' sh {} +

find $NFC_SOURCE_CODE -type f -name android.mk -exec sh -c ' for f; 
do
mv "$f" "${f/%android.mk/Android.mk}"; 
done' sh {} +
###copy Android.* to project code
if [[ "$TARGET_PRODUCT" == "mc582" || "$TARGET_PRODUCT" == "mc582_gms" ]]; then
#    echo "target_product is mc582, overlay nfc source code from $NFC_SOURCE_CODE"
    rm -rf system/nfc
    cp -r $NFC_SOURCE_CODE/system/nfc system/
#    echo "copy system/nfc"

    rm -rf hardware/nxp
    cp -r $NFC_SOURCE_CODE/hardware/nxp hardware/
#    echo "copy hardware/nxp"

    rm -rf frameworks/base/core/java/android/nfc
    cp -r $NFC_SOURCE_CODE/frameworks/base/core/java/android/nfc frameworks/base/core/java/android/
#    echo "copy frameworks/base/core/java/android/nfc"

    rm -rf frameworks/base/core/java/android/se
    cp -r $NFC_SOURCE_CODE/frameworks/base/core/java/android/se frameworks/base/core/java/android/
#    echo "copy frameworks/base/core/java/android/se"

    rm -rf vendor/nxp
    cp -r $NFC_SOURCE_CODE/vendor/nxp vendor/
#    echo "copy vendor/nxp"

    rm -rf packages/apps/Nfc
    cp -r $NFC_SOURCE_CODE/packages/apps/Nfc packages/apps/
#    echo "copy packages/apps/Nfc"

    rm -rf packages/apps/SecureElement
    cp -r $NFC_SOURCE_CODE/packages/apps/SecureElement packages/apps/
#    echo "copy packages/apps/SecureElement"

else
    :
#    echo "target_product is not mc582"
fi
###reset Android.* to android.*
find $NFC_SOURCE_CODE -type f -name Android.bp -exec sh -c ' for f; 
do
    mv "$f" "${f/%Android.bp/android.bp}";
done' sh {} +

find $NFC_SOURCE_CODE -type f -name Android.mk -exec sh -c ' for f; 
do
    mv "$f" "${f/%Android.mk/android.mk}"; 
done' sh {} +
