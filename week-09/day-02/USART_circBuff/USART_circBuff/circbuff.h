
#ifndef CIRCBUFF_H_
#define CIRCBUFF_H_

typedef struct circ_buff {
    uint8_t buffer[RX_CIRC_BUFF_LEN];
    size_t head;
    size_t tail;
    bool full;
} circ_buff_t;

// Return a struct
circ_buff_t circular_buf_init(uint8_t* buffer, size_t size)



#endif /* CIRCBUFF_H_ */