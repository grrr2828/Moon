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
			int num;
			int location;
			int offSet;
			int size;
			AttributeType type;

			Attribute() {};
			~Attribute() {

			};
		};


		VertexLayout();
		~VertexLayout();

		void SetAttribute(std::string name, int size, int num, int location, AttributeType type = AttributeType::None);

		int stride;

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