#include <kani/macros.hpp>

int main(int argc, char* argv[]) {
    int* i = KANI_NULLPTR;

    const char* str = KANI_CXX_VER_TO_STR(KANI_CXX_VER);
    std::cout << str << " (" << KANI_CXX_VER << ")" << std::endl;

    KANI_STRING_VIEW strview = "Hello World";

#if KANI_CXX_VER > KANI_CXX98
    KANI_SHARED_MUTEX mtx;
    KANI_SHARED_UNIQUE_LOCK lock(mtx);
#endif

    return 0;
}