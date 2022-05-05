//default constructor
template<typename T>
UniquePtr<T>::UniquePtr() : _p(nullptr){}
//constructor
template<typename T>
UniquePtr<T>::UniquePtr( T* p) : _p(p){}
//make_unique
template <typename T>
UniquePtr<T> make_unique(T t){
    UniquePtr<T> _p(new T(t));
    return _p;
}
//destructor
template<typename T>
UniquePtr<T>::~UniquePtr( ) {
    delete _p;
}
//move constructor
template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr && Obj){
    __cleanup__(); // cleanup any existing data
    this->_p = Obj._p;
	Obj._p = nullptr; 
}
//move assignment
template<typename T> 
UniquePtr<T>& UniquePtr<T>::operator=(const UniquePtr<T> && Obj){
    __cleanup__(); // cleanup any existing data

	// Transfer ownership of the memory pointed by dyingObj to this object
	this->ptr = Obj._p;
	Obj._p = nullptr;
}
//reset function without input
template<typename T>
void UniquePtr<T>::reset()
{
    delete _p;
   _p=nullptr;
}
//reset function with input
template<typename T>
void UniquePtr<T>::reset(T* a)
{
   reset();
   _p = a;
}    
