#include <iostream>
#include <vector>
#include <string>
#include <fc/io/raw.hpp>


class Package {
public:
   Package() {}
   Package(uint16_t id_, std::string name_): id(id_), name(name_){}
   uint16_t    id = 0;
   std::string name = "default";
};

std::ostream& operator<<(std::ostream& os, const Package& p)
{
   os << p.id << '-' << p.name;
   return os;
}


int main() {
   std::vector< char > buffer;
   Package src(1, "Igor");
   Package dst;
   std::cout << "src: " << src << " | dst: " << dst << std::endl;

   auto size = fc::raw::pack_size( src );
   buffer.resize( size );
   fc::datastream< char* > ds( buffer.data(), size );
   fc::raw::pack( ds, src );

   fc::datastream< const char* > ds_dst( buffer.data(), buffer.size() );
   fc::raw::unpack( ds_dst, dst );

   std::cout << "src: " << src << " | dst: " << dst << std::endl;
   return 0;
}

FC_REFLECT( Package, (id)(name) )