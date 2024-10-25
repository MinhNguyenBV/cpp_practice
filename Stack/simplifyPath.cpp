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


class PathSimplifier {
public:
    std::string simplifyPath(const std::string& path) {
        std::deque<std::string> pathParts = tokenize(path, '/');
        std::deque<std::string> simplifiedParts = processTokens(pathParts);
        return buildSimplifiedPath(simplifiedParts);
    }

private:
    std::deque<std::string> tokenize(const std::string& path, char delimiter) {
        std::stringstream ss(path);
        std::deque<std::string> tokens;
        std::string token;

        while (std::getline(ss, token, delimiter)) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }

    std::deque<std::string> processTokens(const std::deque<std::string>& tokens) {
        std::deque<std::string> result;

        for (const std::string& token : tokens) {
            if (token == ".") {
                continue;
            }
            else if (token == "..") {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else {
                result.push_back(token);
            }
        }

        return result;
    }

    std::string buildSimplifiedPath(const std::deque<std::string>& tokens) {
        if (tokens.empty()) {
            return "/";
        }

        std::string simplifiedPath;
        for (const std::string& token : tokens) {
            simplifiedPath += "/" + token;
        }

        return simplifiedPath;
    }
};
