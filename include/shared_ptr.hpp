template<typename T>
SharedPtr<T>::SharedPtr() : _p(nullptr), refCount(new uint(0)){}

template<typename T>
SharedPtr<T>::SharedPtr( T* p) : _p(p), refCount(new uint(1)){}


template<typename T>    
    SharedPtr<T>::SharedPtr(const SharedPtr<T> & obj)
{
    this->_p = obj._p; // share the underlying pointer
    this->refCount = obj.refCount; // share refCount
    if (nullptr != obj._p)
    {
        // if the pointer is not null, increment the refCount
        (*this->refCount)++; 
    }
}
template<typename T> 
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T> & obj)
{
    // cleanup any existing data

    // Assign incoming object's data to this object
    this->_p = obj._p; // share the underlying pointer
    this->refCount = obj.refCount; // share refCount
    if (nullptr != obj._p)
    {
        // if the pointer is not null, increment the refCount
        (*this->refCount)++; 
    }
}
template<typename T>
void SharedPtr<T>::reset()
{
    (*refCount)--;
   _p=nullptr;
   if (refCount==0)
    delete _p;
}
template<typename T>
void SharedPtr<T>::reset(T* a)
{
   reset();
   _p = a;
   *refCount=1;
// //    _p=nullptr;
//    if (refCount==0)
//          delete _p;
        
}