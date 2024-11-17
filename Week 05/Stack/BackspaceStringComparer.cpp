bool backspaceCompare(string s, string t) {
	stack<char> sStack;
	stack<char> tStack;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] != '#') {
			sStack.push(s[i]);
		}
		else if(!sStack.empty()){
			sStack.pop();
		}
	}

	for (size_t i = 0; i < t.length(); i++)
	{
		if (t[i] != '#') {
			tStack.push(t[i]);
		}
		else if (!tStack.empty()) {
			tStack.pop();
		}
	}

	while (!sStack.empty() && !tStack.empty()){
		if (sStack.top() != tStack.top()) {
			return false;
		}
		sStack.pop();
		tStack.pop();
	}

	if (sStack.empty() && tStack.empty()) {
		return true;
	}
	else return false;
}
