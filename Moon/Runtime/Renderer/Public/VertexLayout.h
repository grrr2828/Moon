#pragma once

#include <string>
#include <vector>

namespace moon {

	class VertexLayout
	{
	public:

		enum AttributeType
		{
			None,
			Vertex,
			Color,
			UV
		};


		struct Attribute
		{
			std::string name;
			int size;
			int count;
			int location;
			int offSet;
			AttributeType type;

			Attribute() {};
			~Attribute() {

			};
		};


		VertexLayout();
		~VertexLayout();

		void SetAttribute(std::string name, int count, int offSet, int location, AttributeType type = AttributeType::None);

		int stride;
		int totalSize;

		const std::vector<Attribute>& GetAttributes()
		{
			return _attributes;
		}
	private:

		void RefreshAttributes();

	private:
		std::vector<Attribute> _attributes;

	};
}