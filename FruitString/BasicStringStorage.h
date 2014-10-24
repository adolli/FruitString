
#ifndef _ADOLLI_BASICSTRINGSTORAGE_
#define _ADOLLI_BASICSTRINGSTORAGE_


namespace adolli
{


	/**
	 * 串线性存储策略
	 * 使用一维数组连续存储，并预留到串长度+1大小，最后一位用于存放终结符号
	 * 终结符号由string类进行添加和管理，该StoragePolicy只负责空间分配
	 */
	template< class T >
	class StringStoragePolicy
	{
	public:

		typedef unsigned int size_type;
		typedef int pos_type;

		StringStoragePolicy()
			: size_(0)
		{
			data_ = new T[1];
		}

		StringStoragePolicy(const T* data, int len)
			: size_(len)
		{
			data_ = new T[len + 1];
			memcpy(data_, data, sizeof(T) * size_);
		}
		StringStoragePolicy(const T c)
			: size_(1)
		{
			data_ = new T[2];
			data_[0] = c;
		}
		StringStoragePolicy(const StringStoragePolicy& rhs)
			: size_(rhs.size_)
		{
			data_ = new T[size_ + 1];
			memcpy(data_, rhs.data_, sizeof(T) * size_);
		}

		~StringStoragePolicy()
		{
			delete [] data_;
		}

		StringStoragePolicy& operator=(const StringStoragePolicy& rhs)
		{
			if (&rhs == this)
			{
				return *this;
			}

			delete [] data_;
			StringStoragePolicy(rhs);
			return *this;
		}


		void Clear()
		{
			delete [] data_;
		}



		StringStoragePolicy& Reserve(size_type n)
		{
			size_type oriSize = size_;
			size_ += n;
			T* newData = new T[size_ + 1];
			memcpy(newData, data_, sizeof(T) * (oriSize + 1));
			delete [] data_;
			data_ = newData;
			return *this;
		}


		T& Get(pos_type n) const
		{
			return data_[n];
		}


		size_type Size() const
		{
			return size_;
		}



	protected:	

		size_type size_;	// 不包含最后一个终结符号
		T* data_;

	};

}

#endif  /*_ADOLLI_BASICSTRINGSTORAGE_*/
