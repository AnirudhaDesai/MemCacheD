#include <stdio.h>
#include <stdint.h>

class Header {
 public:
  char key[251];
  size_t data_size;  
  uint16_t flags;
  int32_t expiration_time;

  Header * prev;
  Header * next;
};

main()
{
	Header ob;
	printf("%ld",sizeof(ob));
}
