// function to drop columns with certain labels
// Ex. df = drop( df1 , drop_vec);   
// drop_vec : { “col_name1”,”col_name2”}

constexpr auto drop(const data_frame& df,std::vector<string>& drop_vec)
{
 data_frame _dropdf;
 
 for(auto col:f.get_col_names())
 {
   if(std::find(drop_vec.begin(), drop_vec.end(), col) == drop_vec.end())
     _dropdf.add_column(col, df[col].get_vector());
 }
 return _dropdf;
}
