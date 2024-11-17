int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue;

	for (size_t i = 0; i < students.size(); i++)
	{
		studentQueue.push(students[i]);
	}
	
	int j = 0, count = 0;

	while (!studentQueue.empty())
	{
		if (count == studentQueue.size() && studentQueue.size() != 0) {
			return studentQueue.size();
		}
		if (studentQueue.front() == sandwiches[j]) {
			j++;
			studentQueue.pop();
			count = 0;
		}
		else {
			int currStudent = studentQueue.front();
			studentQueue.pop();
			studentQueue.push(currStudent);
			count++;
		}
	}


	return studentQueue.size();
};
