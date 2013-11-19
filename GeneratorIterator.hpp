/*
 * GeneratorIterator.h
 *
 *  Created on: Feb 15, 2013
 *      Author: nathan
 */

#ifndef GENERATORITERATOR_H_
#define GENERATORITERATOR_H_

#include <boost/iterator/iterator_facade.hpp>

template<class Generator>
class GeneratorIterator :
		public boost::iterator_facade<
			GeneratorIterator<Generator>,
			typename Generator::yield_type,
			std::forward_iterator_tag>
{
public:
	typedef Generator generator_type;
	typedef typename generator_type::yield_type yield_type;

	typedef typename GeneratorIterator::value_type value_type;
	typedef typename GeneratorIterator::reference reference;

private:
	generator_type* gen;

	friend class boost::iterator_core_access;

	void increment()
	{
		gen->advance();
	}

	reference dereference() const
	{
		return *gen->get();
	}

	bool equal(const GeneratorIterator& rhs) const
	{
		return gen == rhs.gen;
	}

public:

	GeneratorIterator(Generator* gen=nullptr):
		gen(gen)
	{}
};

#endif /* GENERATORITERATOR_H_ */
