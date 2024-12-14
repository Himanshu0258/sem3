def longest_word(string):
  words = string.split()
  longest = max(words, key=len)
  return longest

def char_frequency(string, char):
  return string.count(char)

def is_palindrome(string):
  return string == string[::-1]

def first_appearance(string, substring):
  return string.find(substring)

def word_occurrences(string):
  words = string.split()
  word_count = {}
  for word in words:
    if word in word_count:
        word_count[word] += 1
    else:
        word_count[word] = 1
        return word_count
    
input_string = "Hello , How are you !"
print("Longest word:", longest_word(input_string))
print("Frequency of 'o':", char_frequency(input_string, 'o'))
print("Is palindrome:", is_palindrome(input_string))
print("First appearance of 'are':", first_appearance(input_string, 'are'))
print("Word occurrences:", word_occurrences(input_string))

