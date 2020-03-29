// function for apply function on a particular data frame column
// Ex. auto dfc_1 = apply( df[col_name], [](auto a){return a+a;});
constexpr auto apply(const data_frame_col& dc,std::function<void()>& func)
{
   auto temp = dc.get_vector();
   for_each(temp.begin(),temp.end(),func);
  return dc;
}
 
// function for apply function on dataframe
// Ex. auto df_1 = apply( df, [](auto a){return a+a;});
constexpr auto apply(const data_frame& df,std::function<void()>& func)
{
 data_frame _cmin;
 for(auto col:df.get_col_names())
 {
       auto vec=df[col].get_vector();
       for_each(vec.begin(),vec.end(),func);
       temp.add_column(col,vec);
 }
 return _cmin;
}
