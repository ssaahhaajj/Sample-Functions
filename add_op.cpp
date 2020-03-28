// below function overloads the + operator for the scalar addition in dataframe
// Ex. df1 = df + 1
template<typename T>
constexpr auto operator+(const data_frame& df, const T t)
{
   data_frame _sums;
   for(auto col:df.get_col_names())
   {
       auto vec=df[col].get_vector();
       assert( decltype(*vec.begin()) == decltype(t) );
       for(auto a:vec)
           a=a+t;
       _sums.add_column(col,vec);
   }
   return _sums;
}
 
 
// below functions overloads the + operator for the addition of two dataframes
// Ex. df = df1 + df2
constexpr auto operator+(const data_frame& df1,const data_frame& df2)
{
   assert(df1.get_col_names()==df2.get_col_names());
   data_frame _sum;
   for(auto col:df1.get_col_names())
   {
       assert( decltype(*(df1.[col].get_vector().begin()) == 
        decltype(*(df2.[col].get_vector().begin()));
       template<typename T>
       std::vector<T> 
 vec1=df1[col].get_vector(),vec2=df2[col].get_vector(),temp;
    		 std::transform(vec1.begin(),vec1.end(),vec2.begin(),temp.begin(),
std::plus<T>());
       _sum.add_column(col,temp);
   }
   return _sum;
}
