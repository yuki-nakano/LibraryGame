#ifndef SINGLETON_H
#define SINGLETON_H

namespace engine
{
	//singletonパターン
	template <class T>
	class Singleton
	{
	protected:
		Singleton() {};
		virtual ~Singleton() {};

	private:
		static T* instance;

	public:
		static T* CreateInstance()
		{
			if (instance == nullptr)
			{
				instance = new T();
			}

			return instance;
		};

		static void DeleteInstance()
		{
			delete instance;
			instance = nullptr;
		};

		static T* GetInstance() { return instance; };

	};

	template< class T >
	T* Singleton<T>::instance = nullptr;
}

#endif // !SINGLETON_H
