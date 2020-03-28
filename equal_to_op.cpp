// function overloads == operator for element wise scalar equal to comparison with the dataframe
// Ex. df1 = (df == 100)
template<typename T>
constexpr auto operator == (const data_frame& df, const T t)
{
  data_frame _eqs;
 
  for(auto col:df.get_col_names())
  {
      auto vec=df[col].get_vector();
      std::vector<bool> temp;
 
      assert( decltype(*vec.begin()) == decltype(t) );
 
      for(auto a:vec)
      	   temp.push_back(a==t);
 
      temp.add_column(col,vec);
  }
  return _eqs;
}
 
 
// below functions overloads == operator for returning equals of two dataframes
// Ex. df = (df1 == df2)
constexpr auto operator ==(const data_frame& df1,const data_frame& df2)
{
  assert(df1.get_col_names()==df2.get_col_names());
  
  data_frame _eq;
 
  for(auto col:df1.get_col_names())
  {
       assert( decltype(*(df1.[col].get_vector().begin()) == decltype(*(df2.[col].get_vector().begin()) );
       
       std::vector<bool> temp;
       
       template<typename T>
       std::vector<T> vec1=df1[col].get_vector(),vec2=df2[col].get_vector();
 
       std::transform(vec1.begin(),vec1.end(),vec2.begin(),temp.begin(),[](T& a,T& b){return a==b;});
       
      _eq.add_column(col,temp);
  }
  return _eq;
}
