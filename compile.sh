SCRIPT_NAME=$(basename $0)
SCRIPT_DIR=$(dirname $0)
TARGET_PATH=$SCRIPT_DIR/target/build

echo "SCRIPT_NAME: $SCRIPT_NAME"
echo "SCRIPT_DIR: $SCRIPT_DIR"
echo "TARGET_PATH: $TARGET_PATH"

if [ -d "$TARGET_PATH" ]; then
    echo "exist build folder"
else
    echo "Will be create"
    mkdir -p $TARGET_PATH
    echo "Created"
fi

usage(){
    cat<<USAGE
usage:
    compile.sh [option]
option:
    -l|--log    write output log to file (default: ouput.log)
    -c|--clean  clean target/build folder
    -h|--help   print usage script
USAGE
}

cleanBuild(){
    rm -rf $TARGET_PATH
}

writeLogFile(){
    exec > "$SCRIPT_DIR/ouput.log" 2>&1
    echo "Not support"
}

while [ -n "$1" ]; do
    case $1 in
        -l|--log)
            writeLogFile
            exit
            ;;
        -c|--clean)
            cleanBuild
            exit
            ;;
        -h|--help)
            usage
            exit
            ;;
        *)
            exit
            ;;
    esac
done

rm -rf "$TARGET_PATH"
cmake -S . -B "$TARGET_PATH"

cd "$TARGET_PATH"
make

        
