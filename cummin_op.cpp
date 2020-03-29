// Functor for cumulative minimum operation
template<typename T>
struct cummin_op
{
  constexpr auto operator()(std::vector<T>& vec)
  {
      assert(vec.size()==0);
      auto minm=*(vec.begin());
      std::vector<T> temp;
      for(auto a:vec)
      {
          minm=std::min(a,minm);
          temp.push_back(minm);
      }
      return temp;
  }
};
 
// function for calculating cumulative minimum of data frame column
constexpr auto cummin(const data_frame_col& dc)
{
  return build_by_vec( dc.col_name , mean_op( dc.get_vector()));
}
// function for calculating cumulative minimum of whole data frame
constexpr auto cummin(const data_frame df)
{
 data_frame _cmin;
 for(auto col:df.get_col_names())
 {
     _cmin.add_column( col, cummin_op( df[col].get_vector()));
 }
 return _cmin;
}
