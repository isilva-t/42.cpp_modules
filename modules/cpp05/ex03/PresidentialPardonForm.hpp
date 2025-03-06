#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
	const std::string _target;
	PresidentialPardonForm();

	void	action() const;

public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

};
