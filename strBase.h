#pragma once
class strBase
{
public:
	typedef size_t size_type;

	friend strBase operator+(strBase &a, strBase &b);
	friend strBase operator+(char * a, strBase &b);
	friend strBase operator+(strBase &a, char * b);

	strBase(void);
	strBase(const strBase &other);
	//strBase(const char *other);	
	strBase(const char *other, const size_type length = 0);

	virtual ~strBase(void);

	strBase & operator=(strBase &other);
	
	strBase & operator=(char *other);

	char operator[](int index);

	strBase & operator+=(strBase &add);

	strBase & operator+=(char *add);

	bool isNil() const {
		return baseData->size == 0;
	}

	size_type size() const {
		return baseData->size;
	}

	size_type length() const {
		return baseData->size;
	}

	const char *c_str() const {
		return baseData->str_;
	}

	const char *data() const {
		return baseData->str_;
	}

	void clear(){
		if(isNil())
			return;
		else
			baseData->str_[0] = '\0';
	}

	size_type capacity(){
		return baseData->capacity;
	}

	void append(strBase &add, size_type len);

	//void append(char *add, size_type len);

	void swap(strBase &other){
		baseType *b = baseData;
		baseData = other.baseData;
		other.baseData = b;
	}

	void reserve(size_type size);

private:
	struct baseType{
		size_type size;//the length of string
		size_type capacity;//the length of the array
		char str_[1];
	};

	void init(size_type size){
		init(size, size);
	}

	void init(size_type size, size_type cap){
		if(cap){
			size_type byteNeed = sizeof(baseType) + cap; //need byteNeed size bytes memory
			///base_dat = reinterpret_cast< baseType* >(new char[byteNeed]);
			size_type intNeed  = (byteNeed + sizeof(int) - 1) / sizeof(int); //need intNeed size words memory
			baseData = reinterpret_cast< baseType* >(new int[intNeed]);
			baseData->str_[baseData->size = size] = '\0';
			baseData->capacity = cap;
		}
		else{
			
		}
	}
	void set_size(int newSize){
		baseData->str_[baseData->size = newSize] = '\0';
	}

	char *finish() const {
		return baseData->str_ + baseData->size;
	}
	
	char *start() const {
		return baseData->str_;
	}
	
	void quit(){
		if(!isNil()){
			delete baseData;
			baseData = &nilData;
		}
	}

	baseType *baseData;

	static baseType nilData;

	const size_type stZero;
};

