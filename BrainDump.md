STORY 1
S
- At Celigo, I was tasked with building the Data Steward Console - a completely new dashboard designed to give users visibility into integration and flow errors via interactive visualizations and graphs.
- This feature was crucial for an upcoming Gartner demo scheduled for December 2024, and the deadline was just one or one and a half month away. 
- The dashboard had to be built from scratch, follow a newly introduced design system (shadcn + Tailwind), and be ready without dedicated QA support.

T
- I was the sole frontend engineer with bandwidth to take this on. My responsibility was to architect and implement the entire UI, collaborate across teams, handle rapidly changing requirements, and deliver a polished, stable experience in time for the Gartner demo.

A
- I took ownership and scheduled regular meetings with key stakeholders—including engineering managers, product managers, backend architects, and the design team—to define the scope and clarify expectations clearly. Directors of engineering and product management was also involved in this.
- Since dedicated backend APIs weren’t available for every feature, I collaborated closely with backend teams and used existing APIs creatively—transforming raw, unformatted data into rich visualizations on the frontend.
- I implemented complex charts (exceptions by assignee, application, tag, age, etc.), introduced drill-down capabilities, and ensured responsiveness and accessibility—all aligned with the new design system.
Despite last-minute UX changes, I iterated quickly, often turning around UI updates in under 2–3 hours, surprising the PMs and UX head
- I also performed full-cycle testing myself, coordinating with backend developers to ensure quality.

R
- The dashboard improved exception-tracking efficiency by 30% and reduced manual intervention by 40%. The feature was demoed successfully to Gartner.
- I received strong appreciation from leadership for my initiative, speed, and execution under pressure. It remains one of my proudest contributions at Celigo.


STORY 2
S
- While working on optimizing the HTTP Connector Framework at Celigo, I identified performance issues in the Connection Form UI.
- We were making unnecessary API calls and re-rendering the entire form on minor text changes leading to performance degradation.
- I was assigned a spike to address this.

T
- My responsibility was to work with the backend team to reduce redundant calls and improve load times by optimizing the API structure and frontend rendering.
- While I completed my UI development on time, backend integration kept getting delayed. The BE team wasn’t communicating delays clearly, and QA was blocked, as we were approaching a release code freeze.

A
- Instead of escalating right away, I scheduled a 1:1 with the backend developer to understand their situation.
- I learned they were overloaded and unsure of task priorities. I worked with the PM to help reprioritize the backend’s work and proposed that, if needed, we could deliver the changes as a patch after the release.

R
- Communication improved significantly, QA was unblocked
- The patch was delivered on time, and the performance of the Connection Form UI improved.


Miscellaneous
- In October 2024 at Celigo, we were working on the Data Steward Console, a dashboard to track integration errors. This feature was important for an upcoming Gartner demo
- The company’s goal was to ship a minimum viable version of the feature quickly, with limited UI polish, to meet the deadline
- I was the only frontend engineer available for this, and I believed that just shipping a rough version would hurt the user experience. We had recently started using a new design system (ShadCN + Tailwind), and I felt this feature should follow that system for consistency across the platform. The UX team agreed and also pushed for this alignment, but it wasn’t part of the original short-term plan.


- As the sole frontend engineer assigned — due to team bandwidth constraints
- I was responsible for delivering a complex dashboard from scratch, integrating rich visualizations and drill-down capabilities.


- I suggested a middle ground: I would deliver the core functionality quickly so the product team could test it and begin scripting the Gartner demo.
- At the same time, I asked the UX team to create a Figma design based on the new system. I then took 3–4 days to fully align the dashboard with the design system and had the UX team review it for any small fixes.
- I also worked closely with another team managing the design system to make sure everything fit well.

- In the end, we shipped the feature on time and fully aligned with the new design system. It looked great in the Gartner demo and received strong praise from PMs and managers.


### A time when your manager set unreasonable demands
SHOW that You handle unreasonable demands with assertive communication, not complaints.

- Earlier, during our HTTP Connector Framework revamp, I was asked to complete frontend changes and coordinate backend integration with minimal support — all while meeting a tight release deadline.
- I was supposed to optimize the UI to reduce redundant API calls and improve load times. However, I also had to rely on backend changes that weren’t finalized.
- I communicated early that the scope was not fully under my control and suggested a phased approach. I completed my UI spike quickly, and then worked with PMs to reprioritize backend tasks. I also performed extensive testing myself to adopt the zero bug policy that will reduce the QA testing time.
- I stayed flexible, but set clear expectations about what could be delivered on time.
- We met the deadline by delivering the core improvements, and the backend patch was added shortly after.
- My honest feedback also helped in release planning of the feature.

### How do you manage multiple priorities?

When handling multiple features, I start by aligning with PMs and stakeholders to understand which features have the highest impact, especially those critical for customers or tied to business goals. For example, if one feature directly solves a customer pain point or is needed for a high-stakes demo (like the Data Steward Console for Gartner), I’ll prioritize that first.
Engineering epics like improving the loading time of connections form which is not a customer urgent requirement, we can either push it to next release and if it is prioritised by PMs we can go for patch.

break features into smaller deliverables so I can make consistent progress across streams. I maintain regular syncs to track changes in priority, and communicate timelines and trade-offs early — so if something slips, it doesn’t come as a surprise.


### Do you prefer working in a dynamic environment with changing priorities or doing the same type of work repeatedly?
I definitely thrive in a dynamic environment. I enjoy solving new problems, adapting quickly, and finding creative solutions under constraints. At Celigo, priorities often shifted — especially during feature rollouts like the Error Dashboard — and I had to quickly respond to design or PM feedback, even late in the cycle.
Instead of being frustrated, I found it energizing. It gave me room to learn, collaborate, and push the product forward.



### Tell me about a time when you received critical feedback from your manager. How did you respond, and what actions did you take to improve?
- At Celigo, I was working on a new UI enhancement where I was experimenting with different layout patterns and component designs. I was trying to push myself creatively, but I didn’t align enough with the design system or review the team's standard UI patterns.
- After I submitted my first version, my manager gave me direct feedback: the design looked inconsistent with the rest of the product, and I should’ve consulted the new design system (ShadCN + Tailwind) team before going ahead. It felt a bit discouraging at first, but I understood where he was coming from.
- I thanked him for the honest feedback and didn’t take it personally. Instead, I set up a short sync with the design system team to better understand how components were expected to look and behave
- I proactively validate my designs with UX or design leads early in the process. This helped me avoid misalignment later.

- After that, my implementation quality and speed improved significantly.
- I became more confident in aligning with the system and got trusted with major design-led features — like the Data Steward Console, which I built solo.

