#include "file.h"

map<string, vector<Point2> > getPointsFromFile(vector<string> filenames){

    map<string, vector<Point2> > points;

    for (int i=0;i<filenames.size();i++){
        ifstream infile(filenames[i]);
        string line;
        string x;

        while (getline(infile, line))
        {
			//cout<<line.length()<<endl;
			//cout<<"line10: "<<line[10]<<endl;
            string label = line.substr (1,line.length()-2);
            //cout<<"label: "<<label<<endl;
            // cout << "label : " << label << endl;
            while (getline(infile, line))
            {
                //cout<<line.length()<<endl;
                //cout<<line<<endl;
				if(line=="") break;
                istringstream iss(line);
                int x, y;
                iss >> x >> y;
                //cout << "x : " << x << " y : " << y << endl;
                points[label].push_back((Point2){x,y});
            }
        }
    }
	//printf("points --- size: %d\n",points.size());
    return points;
}

// int main(){

//     vector<string> filenames;
//     filenames.push_back("points.txt");

//     getPointsFromFile(filenames);
//     return 0;
// }
