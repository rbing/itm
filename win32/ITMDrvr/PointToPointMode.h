

//
// FUNCTIONS
///////////////////////////////////////////////
int ParseP2PInputFile(const char* in_file, P2PParams *p2p_params);
int ValidateP2PInputs(P2PParams* p2p_params);
int CallP2PMode(DrvrParams* params, P2PParams* p2p_params, IntermediateValues* inter_vals, vector<double>* A__db, long* warnings);
void WriteP2PInputs(FILE* fp, P2PParams* p2p_params);
#ifdef _WIN32
int LoadP2PFunctions(HINSTANCE hLib);
#else
int LoadP2PFunctions(void *);
#endif
void ParseTerrainFile(const char* terrain_file, vector<double>* pfl);
