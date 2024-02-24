set -e
THIS_DIR="$( cd "$( dirname "${BASH_SOURCE}[0]}" )" && pwd )"

mkdir -p $THIS_DIR/build

cmake \
    -DBUILD_TESTS=1 \
    -DCMAKE_BUILD_TYPE=${BUILD_TYPE:-Debug} \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_CXX_COMPILER=clang \
    -DCMAKE_CXX_STANDARD=17 \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
    -DCMAKE_CXX_FLAGS="-lstdc++ -lm" \
    -G "Unix Makefiles" \
    -B "${THIS_DIR}/build/" \
    -S "${THIS_DIR}"

cmake --build build

$THIS_DIR/build/src/Main

# cmake --install

cd $THIS_DIR/build
ctest --extra-verbose

