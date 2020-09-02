FILE_PATH=$1

# translate
node_modules/.bin/bsc -format $FILE_PATH > "${FILE_PATH}s"
# delete old file
rm -f $FILE_PATH