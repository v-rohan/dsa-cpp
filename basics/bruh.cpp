insert(vector<Interval> &intervals, Interval newInterval) {
    bool startposfound = false;
    int startpos = INT_MIN;
    int endpos = INT_MAX;
    bool mergefront = false;
    bool mergeend = false;
    bool endposfound = false;
    for(int i=0; i< intervals.size()-1;i++){
        if(!startposfound){
            if(intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.start){
                startposfound = true;
                mergefront = true;
                startpos = i;
            }
            else if(intervals[i].start > newInterval.start){
                startpos = true;
                startpos = i;
            }
            
        }
        else if(!endposfound){
            if(intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.end){
                endposfound = true;
                mergeend = true;
                endpos = i;
                break;
            }
            else if(intervals[i].start > newInterval.start){
                endposfound = true;
                endpos = i;
                break;
            }
        }
    }
    
    if(startposfound){
        if(mergefront && mergeend){
            Interval inser = Interval(intervals[startpos].start,intervals[endpos].end);
            auto it = intervals.insert(intervals.begin()+startpos,inser);
            it++;
            intervals.erase(it,intervals.begin()+endpos);
        }
        else if(!mergefront && mergeend){
            Interval inser = Interval(newInterval.start,intervals[endpos].end);
            auto it = intervals.insert(intervals.begin()+startpos+1,inser);
            it++;
            intervals.erase(it,intervals.begin()+endpos);
        }
        else if(!mergefront && !mergeend){
            if(endpos < intervals.size()){
            Interval inser = Interval(newInterval.start,newInterval.end);
            auto it = intervals.insert(intervals.begin()+startpos+1,inser);
            it++;
            intervals.erase(it,intervals.begin()+endpos-1);
            }
            else{
            Interval inser = Interval(newInterval.start,newInterval.end);
            auto it = intervals.insert(intervals.begin()+startpos+1,inser);
            it++;
            intervals.erase(it,intervals.end());
            }
        }
        else if(mergefront && !mergeend){
            if(endpos < intervals.size()){
            Interval inser = Interval(intervals[startpos].start,newInterval.end);
            auto it = intervals.insert(intervals.begin()+startpos,inser);
            it++;
            intervals.erase(it,intervals.begin()+endpos-1);
            }
            else{
            Interval inser = Interval(intervals[startpos].start,newInterval.end);
            auto it = intervals.insert(intervals.begin()+startpos+1,inser);
            it++;
            intervals.erase(it,intervals.end());
            }
        }
    }
}