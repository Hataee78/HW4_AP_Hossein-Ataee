#ifndef UNIQUE_PTR
#define UNIQUE_PTR
typedef unsigned int uint;
template<class T>
class UniquePtr
{
private:
T * _p = nullptr;
void __cleanup__()
	{
		if (_p != nullptr)
			delete[] _p;
	}
    
public:
UniquePtr(); //default constructor
UniquePtr(T* p);//constructor
UniquePtr<T> make_unique(T t);
~UniquePtr();
UniquePtr(const UniquePtr & obj) = delete; // copy constructor is deleted
UniquePtr& operator=(const UniquePtr & obj) = delete; // copy assignment is deleted
UniquePtr(UniquePtr && Obj); // move constructor
UniquePtr& operator=(const UniquePtr&& Obj); //move assignment
T* get() {return this->_p;}
T& operator*(){return *(this->_p);}
T* operator->() {return this->_p;}
void reset();
void reset(T* a);
operator bool() const{
		if (_p==nullptr){
			
			return false;
		}
		else{
			return true;	
			
		}	
	}
T* release(){
       T* tmp = _p;
       _p = nullptr;
       return tmp;
    }



};









#include "unique_ptr.hpp"
#endif //UNIQUE_PTR