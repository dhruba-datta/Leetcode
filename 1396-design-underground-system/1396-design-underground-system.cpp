class UndergroundSystem {
    unordered_map<int, pair<string, int> >checkIns;        // id : {stationName, time}
    unordered_map<string, pair<int, int> >routeTimings;    // startStation-endStation : {sumOfTime, count}
public:
    UndergroundSystem() {  }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};           // store id checked in at stationName at time t
    }
    
    void checkOut(int id, string stationName, int t) {
	    //                     startStation       -    endStation
        string startToEnd = checkIns[id].first + '-' + stationName; 
		// update route's total time and count
        routeTimings[startToEnd] = {routeTimings[startToEnd].first + (t - checkIns[id].second), routeTimings[startToEnd].second + 1};
        checkIns.erase(id); // erase checkin data to free up memory
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = routeTimings[startStation + '-' + endStation];
		// divide   total time by total cound to get average route time
        return (double)p.first / p.second;
    }
};