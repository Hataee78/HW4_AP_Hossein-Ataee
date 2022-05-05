#ifndef SHARED_PTR
#define SHARED_PTR
typedef unsigned int uint;
template<class T>
class SharedPtr
{
private:
    T * _p = nullptr;
    uint * refCount = nullptr;
    void __cleanup__()
	{
		(*refCount)--;
		if (*refCount == 0)
		{
			if (nullptr != _p)
				delete _p;    
			// delete refCount;
		}
        _p = nullptr;
	}
public:
    ~SharedPtr(){	__cleanup__();}
    SharedPtr();
    SharedPtr( T* p);
    SharedPtr& operator=(const SharedPtr& obj);
    SharedPtr(const SharedPtr& obj);
	operator bool() const{
		if (_p==nullptr){
			
			return false;
		}
		else{
			return true;	
			(*refCount)--;
		}	
	}
      
    void reset();
    void reset(T* a);
    T* get() {return this->_p;}
    uint use_count() const{return (*refCount);} // *this->refCount
    T& operator*() const{return *this->_p;}
    T* operator->() const{return this->_p;}

};
template <typename T>
SharedPtr<T> make_shared(T t){
    SharedPtr<T> ptr(new T(t));
    return ptr;
}
#include "shared_ptr.hpp"
#endif //SHARED_PTR