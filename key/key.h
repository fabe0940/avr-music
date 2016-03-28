#ifndef _KEY_H_
#define _KEY_H_

typedef void (*_key_press_handler)(char c);
typedef void (*_key_release_handler)(void);

int key_init(_key_press_handler kph, _key_release_handler krh);
char key_get_char(void);

#endif /* _KEY_H_ */
