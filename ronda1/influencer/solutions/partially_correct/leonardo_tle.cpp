#include <bits/stdc++.h>
using namespace std;
using ll = long long;


//======================================
//============STRUCT GLOBALES===========
//======================================
struct COORDINATES{
    ll row = -1, col = -1;
    COORDINATES(ll r, ll c){
        row = r, col = c;
    }
    bool operator<(const COORDINATES other) const{
        if(row != other.row) return row < other.row;
        else return col < other.col;
    }
};
//==========================================
//============CONSTANTES GLOBALES===========
//==========================================
const vector < COORDINATES > just_adyacentes = {COORDINATES(-1,0),COORDINATES(1,0),COORDINATES(0,-1),COORDINATES(0,1)};
const vector < COORDINATES > just_eliminados = {COORDINATES(0,0),COORDINATES(-1,0),COORDINATES(1,0),COORDINATES(0,-1),COORDINATES(0,1)};
const vector < COORDINATES > just_diagonals = {COORDINATES(-1,-1),COORDINATES(-1,1),COORDINATES(1,-1),COORDINATES(1,1)};
const vector < COORDINATES > just_to_update = {COORDINATES(-2,0),COORDINATES(-1,-1),COORDINATES(-1,1),COORDINATES(0,-2),COORDINATES(0,2),COORDINATES(1,-1),COORDINATES(1,1),COORDINATES(2,0)};
//==========================================
//============VARIABLES GLOBALES===========
//==========================================
ll n;
vector < vector < ll > > vec,reach;
multiset < pair < ll , COORDINATES > > ms;
//===============================================
//============DEBUG FUNCTIONS GLOBALES===========
//===============================================
void matrixDebug(vector < vector < ll > >& v){//cerr<<"";for(auto& i : v) {for(auto& j : i) //cerr << "[" << j << "]  "; //cerr << endl;}
    }
void msDebug(multiset < pair < ll , COORDINATES > >& v){//cerr<<"";for(auto& p : v) //cerr << "{" << p.first << ", " << "(" << p.second.row << ' ' << p.second.col << ")} "; //cerr << endl;
    }
//=========================================
//============FUNCIONES GLOBALES===========
//=========================================
bool inbounds(ll row , ll col){
    return 1 <= row and row <= n and 1 <= col and col <= n;
}
void updateReachAndMs(ll row, ll col)
{
    auto it_toErase = ms.find({reach[row][col],COORDINATES(row,col)});
    if(it_toErase == ms.end()) return; //CHECAR SI ESTO DE AQUI ES UN ERROR!
    ms.erase(it_toErase);
    reach[row][col] = vec[row][col];
    for(auto& p : just_adyacentes){
        if(!inbounds(row + p.row, col + p.col)) continue;
        reach[row][col] += vec[row + p.row][col + p.col];
    }
    ms.insert({reach[row][col],COORDINATES(row,col)});
}
//======================================
//============INT MAIN()================
//======================================
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    //ENTRADA DE DATOS
    cin >> n;
    //DECLARACION DE VARIABLES
    vec.resize(n + 2,vector < ll > (n + 2,0)), reach.resize(n + 2,vector < ll > (n + 2,0));
    //ENTRADA DE DATOS
    for(int row = 1 ; row <= n ; row++) for(int col = 1 ; col <= n ; col++) {
        //ENTRADA DE DATOS
        cin >> vec[row][col];
        //UPDATE -> vector reach
        reach[row][col] += vec[row][col];
        for(auto& p : just_adyacentes) reach[row + p.row][col + p.col] += vec[row][col];
    }
    //SETUP reach
    for(int i = 0 ; i < n + 2 ; i++) reach[i][0] = reach[i][n + 1] = reach[0][i] = reach[n + 1][i] = 0;
    //SETUP ms
    for(int row = 1 ; row <= n ; row++) for(int col = 1 ; col <= n ; col++) ms.insert({reach[row][col],COORDINATES(row,col)});  
    
    
    //DECLARACION DE VARIABLES
    ll final_ans_alberto = 0, final_ans_libni = 0;
    set < COORDINATES > vis;

    //BUSCAMOS EL RESULTADO
    for(bool turno = false ; !ms.empty() ; turno = !turno){
        //DEBUG
        //cerr << "\nreach:\n"; matrixDebug(reach);
        //cerr << "\nms:"; msDebug(ms);
        //DECLARACION DE VARIABLES
        auto it = ms.end();
        it--;

        while(!ms.empty()){
            it = ms.end();
            it--;
            if(vis.contains(it->second)) ms.erase(it);
            else break;
        }

        if(ms.empty()) break;

        //DECLARACION DE VARIABLES
        auto pos = it->second;
        auto row = it->second.row;
        auto col = it->second.col;
        
        //UPDATE -> final_ans_alberto
        if(turno) final_ans_alberto += it->first;
        else final_ans_libni += it->first;
        //cerr << "row: " << row << ", col: " << col << "\n";
        //cerr << "final_ans_" << (turno ? "alberto" : "libni") << " += " << it->first << endl;

        //UPDATE -> Eliminados -> vec, ms, reach, vis
        for(auto& add : just_eliminados) {
            //cerr << "Iterating through (" << (row + add.row) << " " << (col + add.col) << ")...\n";
            //FLAG -> Si no esta en los limites del mapa (!inbounds), continuamos
            if(!inbounds(row + add.row, col + add.col)) {
                //cerr << "POSSIBLE ERROR! Got inbounds(" << (row + add.row) << ", " << (col + add.col) << ") == false\n";
                continue;
            }

            //DECLARACION DE VARIABLES
            auto it_toErase = ms.find({reach[row + add.row][col + add.col],COORDINATES(row + add.row, col + add.col)});
            if(it_toErase == ms.end()) {
                //cerr << "POSSIBLE ERROR! Couldn't find {" << reach[row + add.row][col + add.col] << ", (" << (row + add.row) << ", " << (col + add.col) << ")}\n";
                continue; //CHECAR SI ESTO ES UN ERROR!
            }
            ms.erase(it_toErase);
            //ACTUALIZAMOS vec,reach,vis
            vec[row + add.row][col + add.col] = 0;
            reach[row + add.row][col + add.col] = 0;
            vis.insert(COORDINATES(row + add.row, col + add.col)); 
        }

        //UPDATE -> No eliminados -> ms, reach (vec y vis no es necesario que se actualizen)
        for(auto& add : just_to_update) if(inbounds(row + add.row, col + add.col)) updateReachAndMs(row + add.row, col + add.col);
    }
    

    //DEBUG
    //cerr << "\n------------\nFINAL DEBUG:\n";
    //cerr << "vec:\n"; matrixDebug(vec);
    //cerr << "\nreach:\n"; matrixDebug(reach);
    //cerr << "\nms:\n"; msDebug(ms);
    //ANS SEARCH
    //cerr << "final_ans: "; 
    cout << final_ans_libni << " " << final_ans_alberto;
    return 0;
}