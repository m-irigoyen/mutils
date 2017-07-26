#include <mutils/observed.hpp>

#include <mutils/observer.hpp>
#include <mutils/assert.hpp>

namespace mutils
{
	using obsVec = std::vector<Observer*>;

	Observed::Observed()
	{
	}

	Observed::~Observed()
	{
	}

	bool Observed::registerObserver(Observer * obs)
	{
		MUTILS_ASSERT(obs);
		obsVec::iterator it = find(obs);
		if (it != observers_.end())
		{
			observers_.push_back(obs);
			onObserverRegistered(obs);
			return true;
		}
		return false;
	}

	bool Observed::unregisterObserver(Observer * obs)
	{
		MUTILS_ASSERT(obs);
		obsVec::iterator it = find(obs);
		if (it != observers_.end())
		{
			observers_.erase(it);
			return true;
		}
		return false;
	}

	bool Observed::isRegistered(Observer * obs)
	{
		return find(obs) != observers_.end();
	}

	void Observed::notifyObservers()
	{
		for (Observer* o : observers_)
		{
			o->notify();
			onObserverNotified(o);
		}
	}

	std::vector<Observer*>::iterator Observed::find(Observer * obs)
	{
		return std::find(observers_.begin(), observers_.end(), obs);
	}
}

