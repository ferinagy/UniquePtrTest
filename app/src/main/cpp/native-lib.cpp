#include <jni.h>
#include <string>
#include <map>
#include <memory>

void exampleMapIterable()
{
    std::map<std::string, char> mapIterable = {{"foo", 'x'}, {"bar", 'y'}};

    // Android Studio incorrectly reports error for mapIterable: "'map<string, char>' is not a valid range type"
    for (auto mapEntry : mapIterable) {
        //...
    }
}

void exampleUniquePtr()
{
	std::unique_ptr<std::string> uptr(new std::string);
    uptr->size(); // Android Studio incorrectly reports error for unique ptr: "Applying '->' operator to '...' instead of a pointer"

    auto sptr = std::make_shared<std::string>();
    sptr->size(); // Correct for shared_ptr
}

extern "C" JNIEXPORT jstring JNICALL Java_com_example_fnagy_uniqueptrtest_MainActivity_stringFromJNI (
        JNIEnv* env, jobject /* this */)
{
    exampleMapIterable();
    exampleUniquePtr();

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
