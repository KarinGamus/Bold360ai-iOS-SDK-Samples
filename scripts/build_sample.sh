#!/bin/bash

#ARGUMENTS
FOLDER_NAME=$1
SUB_FOLDER_NAME=$2
WORKSPACE_NAME=$3
# SUFFIX='\r'

# echo $FOLDER_NAME
# FOLDER_NAME=${$FOLDER_NAME%$SUFFIX}
# echo $FOLDER_NAME
# SUB_FOLDER_NAME=${$SUB_FOLDER_NAME%$SUFFIX}
# WORKSPACE_NAME=${$WORKSPACE_NAME%$SUFFIX}

# echo cd to $FOLDER_NAME
cd $FOLDER_NAME
if [ $SUB_FOLDER_NAME != "" ]; then
# echo cd to $SUB_FOLDER_NAME
cd $SUB_FOLDER_NAME
fi

pod update --repo-update

echo -e "\nbuild target for $FOLDER_NAME\n"
xcodebuild -scheme $WORKSPACE_NAME -workspace $WORKSPACE_NAME.xcworkspace -sdk iphonesimulator -destination 'platform=iOS Simulator,name=iPhone 6S,OS=9.1' | tee xcodebuild.log | xcpretty
