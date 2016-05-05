#ifndef _ZoO_CORE_KNOWLEDGE_TYPES_H_
#define _ZoO_CORE_KNOWLEDGE_TYPES_H_

#include "../pervasive.h"

#define ZoO_WORD_START_OF_LINE 0
#define ZoO_WORD_END_OF_LINE   1

/* XXX: are we as close to immutable as we want to be? */
extern unsigned int const ZoO_knowledge_punctuation_chars_count;
extern const ZoO_char const ZoO_knowledge_punctuation_chars[7];
extern unsigned int const ZoO_knowledge_forbidden_chars_count;
extern const ZoO_char const ZoO_knowledge_forbidden_chars[8];


enum ZoO_knowledge_special_effect
{
   ZoO_WORD_HAS_NO_EFFECT,
   ZoO_WORD_ENDS_SENTENCE,
   ZoO_WORD_STARTS_SENTENCE,
   ZoO_WORD_REMOVES_LEFT_SPACE,
   ZoO_WORD_REMOVES_RIGHT_SPACE
};

struct ZoO_knowledge_word
{
   size_t word_size;
   ZoO_char * word;
   enum ZoO_knowledge_special_effect special;
   ZoO_index occurrences;
   ZoO_index forward_links_count;
   ZoO_index backward_links_count;
   ZoO_index * forward_links_occurrences;
   ZoO_index * backward_links_occurrences;
   ZoO_index * forward_links;
   ZoO_index * backward_links;
};

struct ZoO_knowledge
{
   ZoO_index words_count;
   ZoO_index * sorted_indices;
   struct ZoO_knowledge_word * words;
};

#endif
