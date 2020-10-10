/**
 * BackTrace: 回溯算法．
 * 解决一个回溯问题，实际上就是遍历一个决策树．
 * 用穷举法找到问题的所有解．
 */

vector<solution> res;

void BackTrace(path，choice_list) {
    if reach termination condition {
        res.push_back(path);
        return;
    }

    for choice in choice_list {
        1. make choice;
        2. BackTrace(path, choice_list);
        3. revert choice;
    }
}