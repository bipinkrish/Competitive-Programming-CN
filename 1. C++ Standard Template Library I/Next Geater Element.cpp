#include <vector>

vector<int> nextGreaterElement(vector<int> input)
{
  vector<int> data;
  int i, j;
  for (i = 0; i < input.size(); i++)
  {

    for (j = i + 1; j < input.size(); j++)
    {

      if (input[j] > input[i])
      {
        data.push_back(input[j]);
        break;
      }
    }

    if (j == input.size())
    {
      data.push_back(-1);
    }
  }

  return data;
}
