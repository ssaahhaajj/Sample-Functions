// Functor for mean operation
template<typename T>
struct mean_op
{
   constexpr auto operator()(std::vector<T>& vec)
   {
       return (std::accumulate(vec.begin(),vec.end(),0.0))/vec.size();
   }
};
 
// function for calculating mean of a particular data frame column
// Ex. mean_col_name = dfmean( df[colm_name] );
constexpr auto dfmean(const data_frame_col& dc)
{
   return mean_op(dc.get_vector());
}
 
// function for calculating mean of whole data frame
// Ex. mean_df_name = dfmean( df );
constexpr auto dfmean(const data_frame& df)
{
  std::vector< std::pair<data_frame_col,T> > _mean;
 
  for(auto col:df.get_col_names())
  {
      _mean.push_back(std::make_pair(col,mean_op(df[col].get_vector())));
  }
  return _mean;
}
