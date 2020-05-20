#include "VertexLayout.h"

namespace moon {

	VertexLayout::VertexLayout()
	{
	
	}


	VertexLayout::~VertexLayout()
	{
		_attributes.clear();
	}

	void VertexLayout::SetAttribute(std::string name, int size, int num, int location, AttributeType type)
	{
		Attribute attr;
		attr.name = name;
		attr.num = num;
		attr.location = location;
		attr.type = type;
		attr.size = size;

		_attributes.push_back(attr);


		RefreshAttributes();
	}

	void VertexLayout::RefreshAttributes()
	{
		stride = 0;
		totalSize = 0;

		int len = _attributes.size();

		int offSet = 0;
		for (size_t i = 0; i < len; i++)
		{
			Attribute& attr = _attributes[i];

			stride += attr.num;
			totalSize += attr.size;

			attr.offSet = offSet;

			offSet += attr.num;

		}

	}


}