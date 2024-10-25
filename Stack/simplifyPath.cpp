string simplifyPath(const string& path) {
        std::stringstream ss (path);

        std::string line;
        std::deque<std::string> dqueue;

        while (std::getline(ss, line, '/'))
        {
	        if (!line.empty()) {
		        if (line == ".." && !dqueue.empty())
			        dqueue.pop_back();
		        else if (line != "..")
			        dqueue.push_back(line);

		        if (line == "." && !dqueue.empty())
			        dqueue.pop_back();
	        }
        }

        std::string ret;

        if (dqueue.empty()) ret += "/";

        while (!dqueue.empty())
        {
	        ret += "/" + dqueue.front();
	        dqueue.pop_front();
        }

        return ret;
}
