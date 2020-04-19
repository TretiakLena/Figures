#pragma once

class Index {
public:
	//_____________FOR_SINGULTON________________________________
	static Index* CreateIndex(int limit) {
		if (!ptr) ptr = new Index(limit);
		return ptr;
	}
	~Index() {
		delete ptr;
	}

	//_______________GET_SET_______________________________________
	int GetIndex()   const {
		return this->index;
	}
	int GetLimit()   const {
		return this->limit;
	}
	void SetIndex(int var) {
		if (var < this->limit and var > -1)
			this->index = var;
	}
	
	//___________________UP_DOWN___________________________________
	void IndexUp() {
		if (this->index >= this->limit - 1) this->index = 0;
		else this->index++;
	}
	void IndexDown() {
		if (this->index <= 0) 
			this->index = this->limit - 1;
		else 
			this->index--;
	}
	void LimitUp() {
		this->limit++;
	}
	void LimitDown() {
		if (this->limit > -1) 
			this->limit--;
	}
	
	//_____________________________________________________
	operator int() const {
		return this->index;
	}
private:
	//__________CONSTRUCTORS_______________________________
	Index() = delete;
	Index(int limit) : index(0), limit(limit) {}
	//_____________________________________________________
	int index;
	int limit;
	static Index* ptr;//сингултон
};


Index* Index::ptr = nullptr;
