#!/usr/bin/env bash

#ARGUMENTS
FOLDER_NAME=$1
SUB_FOLDER_NAME=$2
WORKSPACE_NAME=$3

for i in *; do 
if [[ -f $i ]]; 
then sed -i 's/\r$//' "$i"; 
fi; done

# echo cd to $FOLDER_NAME
cd $FOLDER_NAME
if [ $SUB_FOLDER_NAME != "" ]; then
# echo cd to $SUB_FOLDER_NAME
cd $SUB_FOLDER_NAME
fi

pod update --repo-update

echo -e "\nbuild target for $FOLDER_NAME\n"
xcodebuild -scheme $WORKSPACE_NAME -workspace $WORKSPACE_NAME.xcworkspace -sdk iphonesimulator -destination 'platform=iOS Simulator,name=iPhone 6S,OS=9.1' | tee xcodebuild.log | xcpretty
