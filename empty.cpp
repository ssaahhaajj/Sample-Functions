// function to check if data frame is empty or not
// Ex. bool check_empty = empty(df);
constexpr auto empty(const data_frame& df)
{
 bool isempty=true;
 for(auto col : df.get_col_names())
 {
   if(!df[col].get_vector().empty())
     isempty=false;
 }
 return isempty;
}

// function to check if data frame column is empty or not
// Ex. bool check_empty = empty(df[col_name]);
constexpr auto empty(const data_frame_col& df)
{
  return df[col].get_vector().empty();
}
