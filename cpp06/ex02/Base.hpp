#ifndef BASE_HPP_
#define BASE_HPP_

class Base {
	public:
		virtual	~Base() {}; // polymorphism needed for dynamic_cast
		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);

	private:
};

#endif  // BASE_HPP_
