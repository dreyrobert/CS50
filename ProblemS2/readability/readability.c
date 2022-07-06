#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int what_grade_is(int letters, int sentences, int words);
int count_letters(string word);
int count_words(string word);
int count_sentences(string word);

int main(void)
{
    string phrase = get_string("Text: ");
    int letters = count_letters(phrase);
    int sentences = count_sentences(phrase);
    int words = count_words(phrase);
    int grade = what_grade_is(letters, sentences, words);
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int what_grade_is(int letters, int sentences, int words)
{
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);
    return grade;
}

int count_letters(string word)
{
    int count = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            count += 1;
        }
        if (islower(word[i]))
        {
            count += 1;
        }
    }
    return count;
}

int count_words(string word)
{
    int spaces = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == ' ')
        {
            spaces += 1;
        }
    }
    return spaces + 1;
}

int count_sentences(string word)
{
    int count = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == '.')
        {
            count += 1;
        }
        if (word[i] == '?')
        {
            count += 1;
        }
        if (word[i] == '!')
        {
            count += 1;
        }
    }
    return count;
}