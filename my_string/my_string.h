#pragma once

namespace containers {

class String final {
	size_t size_ = 0, capacity_ = 0;
	char* data_ = nullptr;

public:
	String() = default;
	String(const char* str)
		: size_(length(str) + 1), capacity_(size_), data_(new char[capacity_]) {
		copy(str, str + size_, data_);
	}
	String(const String& other)
		: size_(other.size_), capacity_(other.capacity_), data_(new char[capacity_]) {
		copy(other.data_, other.data_ + capacity_, data_);
	}
	String& operator=(const String& other) {
		delete[] data_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		data_ = new char[capacity_];
		copy(other.data_, other.data_ + capacity_, data_);
		return *this;
	}

public: //acessors
	using size_type = size_t;

	size_t size() const {
		return size_ - 1;
	}
	size_t capacity() const {
		return capacity_;
	}
	char* c_str() const {
		return data_;
	}
	char& operator[](size_t pos) {
		return data_[pos];
	}

private:
	char* copy(const char* src_beg, const char* src_end, char* dst_beg) {
		while (src_beg != src_end) {
			*dst_beg = *src_beg;
			++src_beg; ++dst_beg;
		}
		return dst_beg;
	}
	size_t length(const char* str) {
		const char* p = str;
		while (*p) {
			++p;
		}
		return p - str;
	}
};

}